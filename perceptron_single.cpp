#include <bits/stdc++.h>

using namespace std;

void readCSV(const string& filename, vector<vector<double>>& firstTwoColumns, vector<double>& lastColumn) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Could not open the file " << filename << endl;
        return;
    }

    while (getline(file, line)) {
        stringstream lineStream(line);
        string cell;

        vector<double> row;

        if (getline(lineStream, cell, ',')) {
            row.push_back(stod(cell));
            if (getline(lineStream, cell, ',')) {
                row.push_back(stod(cell));
                if (getline(lineStream, cell, ',')) {
                    lastColumn.push_back(stod(cell)); // Normalize last column
                    firstTwoColumns.push_back(row);
                }
            }
        }
    }

    file.close();
}

class Perceptron {
private:
    vector<double> weights;
    double bias;
    double lr;

public:
    Perceptron(int n_inputs, double lr) {
        weights.resize(n_inputs);
        this->lr = lr;
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(-0.1, 0.1); 

        for (int i = 0; i < n_inputs; i++) {
            weights[i] = dis(gen);
        }
        bias = dis(gen);
    }

    double predict(const vector<double> &inputs) {
        double sum = bias;
        for (int i = 0; i < inputs.size(); i++) {
            sum += weights[i] * inputs[i];
        }
        return sum;
    }

    void train(vector<vector<double>> &data, vector<double> &labels, int epochs) {
        for (int e = 0; e < epochs; e++) {
            double totalError = 0.0;
            for (int i = 0; i < data.size(); i++) {
                double pred = predict(data[i]);
                double actual = labels[i];
                double error = actual - pred;
                for (int j = 0; j < data[i].size(); j++) {
                    weights[j] += lr * error * data[i][j];
                }
                bias += lr * error;
                totalError += error * error;
            }
            totalError /= data.size();
            totalError = sqrt(totalError);
            cout << "Epoch " << e + 1 << ", RMS Error: " << totalError << endl;
        }
    }
    void Scale(vector<vector<double>> &data, vector<double> &labels){
        vector<double> feature_max;
        vector<double> feature_min;
        double lable_max = max_element(labels.begin(), labels.end());
        double lable_min = min_element(labels.begin(), labels.end());
        for(int i = 0; i <data[0].size(); i++){
            double max_ = INT_MIN;
            double min_ = INT_MAX;
            for(int j = 0; j <data.size(); j++){
                double x = data[j][i];
                max_ = max(max_,x);
                min_ = min(min_, x);
            }
            feature_max.push_back(max_);
            feature_min.push_back(min_);
        }
        for(int i = 0; i <data[0].size(); i++){
            for(int j = 0; j <data.size(); j++){
                data[j][i] = (data[j][i]-feature_min[i])/(feature_max[i]-feature_min[i]);
            }
        }
        for(auto& x: labels){
            x = (x-lable_min)/(lable_max-lable_min);
        }

        
    }
};

int main() {
    string filename = "data.csv";
    vector<vector<double>> firstTwoColumns;
    vector<double> lastColumn;

    readCSV(filename, firstTwoColumns, lastColumn);


    Perceptron p(2, 0.01);
    p.Scale(firstTwoColumns, lastColumn);
    p.train(firstTwoColumns, lastColumn, 10000);

    return 0;
}

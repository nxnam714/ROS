#include <iostream>
#include <cstring>

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#define MAX_LINE_LENGTH 1024

int main(int narg, char** argv) {
    ifstream inFile(argv[1]);
    ofstream myfile;
    int result[100][3];
    int result_length = 0;
    int ret[3][2];

    myfile.open("hslout.txt");

    if (inFile){
        string line;
        char buffer[MAX_LINE_LENGTH];
        while (getline(inFile, line)){
            // On Windows, lines on file ends with \r\n. So you have to remove \r
            if (line[line.length() - 1] == '\r')
                line.erase(line.length() - 1);

            if (line.length() > 0) {
                char    subStr[10];
                int     i = 3, j = 0;
                int     counter = 0;

                memset(subStr, 0, 10);
                while(line.data()[j]){
                    if(line.data()[j] == ',' || line.data()[j] == ')'){
                        switch(counter){
                            case 0:
                                strncpy(subStr, line.data() + i, j - i - 1);                                
                            case 1:
                                strncpy(subStr, line.data() + i + 1, j - i - 1);
                            case 2:
                                strncpy(subStr, line.data() + i + 1, j - i - 1);                                
                        }

                        stringstream strStream(subStr);
                        int tmp;
                        strStream >> tmp;
                        result[result_length][counter] = tmp;
                        //cout << result_length << " - " << counter << " - " << tmp << " ";
                        counter++;
                        i = j + 1;
                    }
                    j++;
                }
            }
            //cout << endl;
            result_length++;
        }
    }
    for (int i = 0; i < result_length; i++){
        // cout << result[i][0] << " "
        //         << result[i][1] << " "
        //         << result[i][2] << endl;

    }
    //cout << endl;

    for (int i = 0; i < 3; i++){
        ret[i][0] = result[0][i];
        ret[i][1] = result[0][i];
    }

    for (int i = 0; i < result_length; i++){
        for (int j = 0; j < 3; j++){
            if (result[i][j] < ret[j][0]){
                ret[j][0] = result[i][j];
            }
            if (result[i][j] > ret[j][1]){
                ret[j][1] = result[i][j];
            }
        }
    }

    for (int j = 0; j < 3; j++){
        //cout << ret[j][0] << " " << ret[j][1] << endl;
    }
    //cout << endl;

    for (int i = 0; i < result_length; i++){
        result[i][0] = result[i][0] * 179 / 360;
        result[i][1] = result[i][1] * 255 / 100;
        result[i][2] = result[i][2] * 255 / 100;
    }

    for (int i = 0; i < result_length; i++){
        /*cout << result[i][0] << " "
                << result[i][1] << " "
                << result[i][2] << endl;*/

    }
    //cout << endl;
    for (int i = 0; i < 3; i++){
        ret[i][0] = result[0][i];
        ret[i][1] = result[0][i];
    }

    for (int i = 0; i < result_length; i++){
        for (int j = 0; j < 3; j++){
            if (result[i][j] < ret[j][0]){
                ret[j][0] = result[i][j];
            }
            if (result[i][j] > ret[j][1]){
                ret[j][1] = result[i][j];
            }
        }
    }

    for (int j = 0; j < 3; j++){
        cout << ret[j][0] << " " << ret[j][1] << endl;
        myfile << ret[j][0] << " " << ret[j][1] << endl;
    }
    myfile.close();
    return 0;
}
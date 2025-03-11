#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <unordered_map>
#include <string>
#include "algorithm"
using namespace std;

#define file_name "test2.txt"

void exercise_1() {

    int x;
    cin >> x;
    cout << x << "\n\n";
    string a;

    scanf("%d", &x);
    printf("%d", x);
    printf("\n\n");

    FILE* file_input = fopen("input.txt", "r");
    FILE* file_output = fopen("output.txt", "w");

    while (!feof(file_input)) {
        fscanf(file_input, "%s", &a);
        fprintf(file_output, "%s", a);
        fprintf(file_output, "\n");
    }

    fclose(file_input);
    fclose(file_output);

    int fd_input = _open("input.txt", _O_RDONLY);
    int fd_output = _open("output.txt", _O_WRONLY);

    if (fd_input == EOF) {
        perror("Файл пустой, отвечаю");
    }

    char buff[100];
    int BytesRead = _read(fd_input, buff, 100);
    _write(fd_output, buff, BytesRead);
    _close(fd_input);
    _close(fd_output);
}

void exercise_hash() {
    unordered_map<string, int> hashMap;

    FILE* file_input = fopen(file_name, "r");
    string collection[50];
    char buff[100];
    short i = 0;

    while (!feof(file_input)) {
        fscanf(file_input,"%s", buff);
        collection[i] = buff;
        for (size_t j = 1; j <= collection[i].size(); ++j) {
            string substring = collection[i].substr(0, j); 
            hashMap[substring]++;  
        }
       
        i++;
    }

    int maxLen = 0;
    int maxCount = 0;
    string maxLenStr;
    string maxCountStr;

    for (const auto& pair : hashMap) {
        if (pair.first.size() > maxLen and pair.second != 1) {
            maxLen = pair.first.size();
            maxLenStr = pair.first;
        }

        if (pair.second >= maxCount and pair.second != 1 and pair.first.size() > maxCountStr.size()) {
            maxCount = pair.second;
            maxCountStr = pair.first;
        }
    }

    cout << maxLenStr << "  " << maxCountStr;

}

void exercise_2() {
    FILE* file_input = fopen(file_name, "r");
    string collection[50];
    string longer_word;
    string mainer_word;
    short maxCount = 0;
    char buff[100];
    short i = 0;

    while (!feof(file_input)) {
        fscanf(file_input, "%s", buff);
        collection[i] = buff;
        i++;
    }

    fclose(file_input);

    sort(begin(collection), begin(collection)+i);

    for (int j = 0; j < i; j++) {
        string curr = collection[j];
        int s = 1;
        while (collection[j + s].find(curr) == 0) {
            s++;
            if (longer_word.length() < curr.length()) {
                longer_word = curr;
            }
        }
        if ((s-1) > maxCount) {
            maxCount = s - 1;
            mainer_word = curr;
        }     
    }
    

/*    if (longer_word == "") longer_word = "NO";
    if (mainer_word == "") mainer_word = "NO";*/ 

    FILE* file_output = fopen("mainer.txt", "w");
    if (maxCount > 0) {
        fprintf(file_output,"%s", mainer_word + " " + to_string(maxCount));
    }
    else {
        mainer_word = "NO";
        fprintf(file_output, "NO");
    }
    fclose(file_output);
        
    
    string answer;
    file_output = fopen("longer.txt", "w");
    if (longer_word != "") {
        answer = longer_word + " ";
        for (int j = 0; j < i; j++) {
            if (collection[j] != longer_word and collection[j].find(longer_word) == 0) answer += collection[j] + " ";
        }

        fprintf(file_output, "%s", answer);
    }
    else {
        answer = "NO";
        fprintf(file_output, "NO");
    }
    fclose(file_output);

    //for (int j = 0; j < i; j++) cout << collection[j] << "\n";
    cout << answer << "   " << mainer_word << "  " << maxCount << "\n";
}

int main()
{
    setlocale(LC_ALL, "ru");
    exercise_2();
    //exercise_hash();
}

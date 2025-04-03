#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

string replaceSharp(string melody) {
    map<string, char> sharpNotes = {{"C#", 'c'}, {"D#", 'd'}, {"F#", 'f'}, {"G#", 'g'}, {"A#", 'a'}, {"B#", 'b'}};
    string result = "";
    for (size_t i = 0; i < melody.size(); i++) {
        if (i + 1 < melody.size() && melody[i + 1] == '#') {
            string note = melody.substr(i, 2);
            result += sharpNotes[note];
            i++; 
        } else {
            result += melody[i];
        }
    }
    return result;
}

int getMinutes(string time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

string solution(string m, vector<string> musicinfos) {
    m = replaceSharp(m);
    string answer = "(None)";
    int maxPlayTime = 0;
    
    for (const string &info : musicinfos) {
        stringstream ss(info);
        vector<string> parts;
        string temp;
        while (getline(ss, temp, ',')) {
            parts.push_back(temp);
        }
        
        int stime = getMinutes(parts[0]);
        int etime = getMinutes(parts[1]);
        int playTime = etime - stime;
        if (playTime <= 0) continue;
        
        string melody = replaceSharp(parts[3]);
        string playedMusic = "";
        for (int i = 0; i < playTime; i++) {
            playedMusic += melody[i % melody.size()];
        }
        
        if (playedMusic.find(m) != string::npos) {
            if (playTime > maxPlayTime) {
                answer = parts[2];
                maxPlayTime = playTime;
            }
        }
    }
    
    return answer;
}


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> solution(string capacities, vector<string> requests) {

    // Parse capacities string
    unordered_map<string, int> workshopCapacities;
    stringstream ss_caps(capacities);
    string segment;

    while (getline(ss_caps, segment, ',')) {
        size_t colonPos = segment.find(':');
        if (colonPos != string::npos) {
            string name = segment.substr(0, colonPos);

            // Trim whitespace
            name.erase(0, name.find_first_not_of(" "));
            name.erase(name.find_last_not_of(" ") + 1);

            int cap = stoi(segment.substr(colonPos + 1));
            workshopCapacities[name] = cap;
        }
    }

    vector<string> results;

    // Process requests (FCFS)
    for (const string& request : requests) {

        size_t pipePos = request.find('|');
        string prefsPart = (pipePos == string::npos) ? "" : request.substr(pipePos + 1);

        // Empty preferences
        if (prefsPart.empty() || prefsPart.find_first_not_of(" ") == string::npos) {
            results.push_back("NONE");
            continue;
        }

        stringstream ss_prefs(prefsPart);
        string pref;
        bool assigned = false;

        while (getline(ss_prefs, pref, ',')) {

            // Trim whitespace
            pref.erase(0, pref.find_first_not_of(" "));
            pref.erase(pref.find_last_not_of(" ") + 1);

            // Check availability
            if (workshopCapacities.count(pref) && workshopCapacities[pref] > 0) {
                results.push_back(pref);
                workshopCapacities[pref]--;
                assigned = true;
                break;
            }
        }

        if (!assigned) {
            results.push_back("NONE");
        }
    }

    return results;
}
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


// Knapsack algorithm---------------------------
    // Approach: we want the most profit while taking no more space than the space of the bag.
    // We will sort the Object array in descending order acc. to P/W of each.
    // Then one by one, we'll subtract the bagSpace with the weight of the object, add its profit and then repeat__
    // __until no object can fully be added. Now we'll add the current max P/W object fractionally so that the bag gets just full, add its profit fractionally too, and exit.
struct Object {
    char id;
    int profit;
    int weight;
};
bool comparisonKnapsack(Object a, Object b) { //function used in sort() to arrange them in descending order
    return (a.profit / a.weight) > (b.profit / b.weight);
}
void knapSack() {

    // Question

    Object objects[] = {
        {'a', 10, 2}, {'b', 5, 3}, {'c',15, 5}, {'d',7,7}, {'e',6,1}, {'f',18, 4}, {'g',3, 1}
    };

    float spaceInBag = 15;

    // Answer

    int n = sizeof(objects) / sizeof(Object);

    sort(objects, objects + n, comparisonKnapsack);

    float profit = 0;
    queue<char>objectsChosen;

    for (auto object : objects) {
        if (spaceInBag < object.weight) {
            float fraction = spaceInBag / object.weight;

            profit += object.profit * fraction; // Add the profit fractionally as the object goes in partially
            spaceInBag -= object.weight * fraction; // Subtract the space from the bag fractionally as the object goes in (this time the bag should get completely filled)

            cout << "Profit: " << profit << " | Last fraction: " << fraction << "\nObjects chosen: ";
            while (!objectsChosen.empty()) {
                cout << objectsChosen.front() << " ";
                objectsChosen.pop();
            }

            break;
        }
        else {
            profit += object.profit; // Add the profit as the object goes in
            spaceInBag -= object.weight; // Subtract the space from the bag as the object goes in (this time the bag should get completely filled)
            objectsChosen.push(object.id);
        }
    }
}
// ---------------------------

int main() {

    knapSack();

    return 0;
}
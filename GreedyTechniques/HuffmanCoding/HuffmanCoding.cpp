// #include<iostream>
// #include<bits/stdc++.h>
// #include<algorithm>
// using namespace std;

// // Message: BCCABBDDAECCBBAEDDC (contains 20 alphabets)
// // ASCII : 8 Bit
// // A: 65 : 01000001
// // B: 66 : 01000011
// // C: 67 : 01000100
// // D: 68 : 01000101
// // E: 69 : 01000110
// // normally, we would need (8 bits)*20 = 160 bits : this is the case without encoding

// // 8 bit ASCII codes are for 128 characters. But for only 5 characters, we'll need less

// // having n bits enables us to represent 2^n characters because 1 bit can represent upto 2, 2 can upto 4, 3 can upto 8, and so on.
// // here, 2^n = 5.
// // So, n = log 5 to the base 2. Which is >2 and <3. So, we will take the ceil value 3.
// // we require 3 bits for each character

// // Our code table
// // A = 000
// // B = 001
// // C = 010
// // D = 011
// // E = 100

// // We'll use these instead of ASCII codes

// // Now, the size of the message = 20*3 = 60 bits.

// // But, how will anybody know that what code is assigned to which digit?
// // To make sure they know, we also have to expose our code table with the message so that anybody can decode.
// // The additional size required todo that = 5*(8 bits for characters(ASCII) in the table) + 5*(3 bits for our codes in the table) = 40 + 15 = 55.
// // So, the total size = 60 + 55 = 115. Which is less than original 160 bits

// // chars  ASCII   Custom
// // A:    01000001 : 000
// // B:    01000011 : 001
// // C:    01000100 : 010
// // D:    01000101 : 011
// // E:    01000110 : 100

// // This was with fixed sized codes


// // But Huffman says that we don't have to take fixed sized codes for the alphabets.
// // A few alphabets may be appearing less number of times and some may be appearing more number of times
// // If we give small sized codes for the more appearing characters, then the size of the message will definitely be reduced


// // Huffman encoding follows Optimal Merge pattern.
// // Message: BCCABBDDAECCBBAEDDC (contains 20 alphabets)
// // char count code
// //  A     3  
// //  B     5
// //  C     6
// //  D     4
// //  E     2
// // Approach to get our own variable sized codes:  
// // alphabets should be arranged in the order of their least number of counts
// // E A D B C
// // Following the OMP, merge two with the smallest frequencies and make one node again and again
// // while doing this, append the code of the smaller at each comparison with 0, and with 1 of the other(larger one) on the left side. like "1000"+'1' = "11000"

// struct Node {
//     char id;
//     int frequency = 1; //When added, the node will have 1 freq... because it has been added>>>
//     string code = "";

//     Node(char id) {
//         this->id = id;
//     }
//     void append(char num) {
//         this->code = num + this->code;
//     }
// };
// void appendAndSetSameFrequencyNodes(vector<Node>&nodes){

// }

// void mergeTwoAndAppendCodes(vector<Node>& nodes) {
//     int smallestFreqIdx1 = 0;
//     for (int i = 0; i < nodes.size(); i++) {
//         if (nodes[smallestFreqIdx1].frequency > nodes[i].frequency) {
//             smallestFreqIdx1 = i;
//         }
//     }
//     int smallestFreqIdx2 = 0; //larger then the 1st one. i.e., appends 1
//     for (int i = 0; i < nodes.size(); i++) {
//         if (nodes[smallestFreqIdx1].frequency > nodes[i].frequency && i != smallestFreqIdx1) {
//             smallestFreqIdx2 = i;
//         }
//     }

//     int combinedFreq = nodes[smallestFreqIdx1].frequency + nodes[smallestFreqIdx2].frequency;
//     appendAndSetSameFrequencyNodes();

//     nodes[smallestFreqIdx1].append(0);
//     nodes[smallestFreqIdx2].append(1);

//     nodes[smallestFreqIdx1].frequency = combinedFreq;
//     nodes[smallestFreqIdx2].frequency = combinedFreq;
// }

// bool comparisonHuffman(Node a, Node b) {
//     return a.frequency < b.frequency;
// }

// void huffmanCoding() {

//     string message = "BCCABBDDAECCBBAEDDC";

//     vector<Node>nodes;
//     for (auto c : message) {
//         int exists = false;
//         for (auto node : nodes) {
//             if (node.id == c) {
//                 exists = true;
//                 node.frequency++;
//             }
//         }
//         if (!exists) {
//             nodes.push_back(Node(c));
//         }
//     }
//     sort(nodes.begin(), nodes.end(), comparisonHuffman);

// }

// int main() {

//     huffmanCoding();

//     return 0;
// }
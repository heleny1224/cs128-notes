## Strings

std::string s = "hello";

s[i]                  // access character
s.size()              // number of characters
s.push_back(c)        // add character
s.pop_back()          // remove last character
s += "abc"            // append
s.find("abc")         // find substring
s.substr(start, len)  // extract substring

'A'                   // char
"ABC"                 // string

for (char c : s) {
    ...
}

## Vector of Vectors

std::vector<std::vector<int>> matrix;

matrix[i]             // ith row
matrix[i][j]          // element at row i, column j

matrix.size()         // number of rows
matrix[i].size()      // number of elements in row i

matrix.push_back({1, 2, 3});  // add row
matrix[i].push_back(x);       // add to row i


## Sets

std::set<int> s;

s.insert(x);       // add x
s.erase(x);        // remove x
s.contains(x);     // check whether x exists
s.size();          // number of elements
s.empty();         // whether empty

// Properties:
// - unique elements
// - sorted
// - no indexing


## Maps

std::map<KeyType, ValueType> m;

m[key] = value;    // insert/update
m[key];            // access value
m.at(key); // access existing key 
m.contains(key);   // check key
m.erase(key);      // remove key/value pair
m.size();          // number of key/value pairs
m.insert(...); // insert pair 
m.empty(); // true if empty 
m.clear(); // remove everything

// Map = key → value
// Keys are unique


## Iterating over a map

for (const auto& pair : m) {
    pair.first;     // key
    pair.second;    // value
}

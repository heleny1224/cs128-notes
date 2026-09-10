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

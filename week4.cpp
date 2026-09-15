STRUCTS
======

//struct → creates a custom type that groups related data

struct Score {
  unsigned int assessment_id = 0;
  int points = -1;
  bool is_late = false;
};

//Create object:
Score entry;

//Access member:
entry.points
entry.assessment_id

//Initialize:
Score entry{7, 88, false};

//C++20 designated initialization:
Score entry{.assessment_id = 7, .points = 88};

//Nested struct:
sub.score.points

//Copy:
Score b = a;

//Vector of structs:
std::vector<Score> log;

//Loop:
for (const Score& entry : log) { ... }

//Function parameters:
Score x         // → copy
Score& x        // → modify original
const Score& x   //→ read only, no copy

//Return struct:
Score Best(...)

//Structured bindings:
auto [a,b,c] = entry;      // → copies
auto& [a,b,c] = entry;     // → references
const auto& [a,b,c] = entry //→ read-only references

/* Important:
- Struct groups related data together
- Members are accessed with .
- Default copying copies each member
- string/vector members are copied too
- == is NOT automatically provided for this struct
- << is NOT automatically provided
- Initialize primitive members before reading them
*/

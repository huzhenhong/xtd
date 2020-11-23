#include <xtd/xtd>
#include <iostream>

using namespace std;
using namespace xtd;

int main() {
  for (size_t index = 0; index < 10; index++)
    cout << format("{:X}", guid::new_guid()) << endl;
}

// This code can produces the following output:
//
// {0x8b29b084,0x4be2,0x4a1d,{0x93,0x44,0x59,0xea,0x59,0x9b,0x5b,0xaa}}
// {0x27e83739,0x1d25,0x47b0,{0xbc,0x22,0xb7,0x0b,0x96,0x3d,0xf4,0x1b}}
// {0x7516c2d6,0x1c88,0x46d2,{0x9c,0x17,0xd4,0x18,0xb5,0x7d,0x23,0xb4}}
// {0xec556311,0x969b,0x4095,{0x9e,0xce,0x40,0x27,0x73,0x3d,0x55,0xc5}}
// {0x35674f52,0x154e,0x4dce,{0xb1,0xaa,0x58,0x4d,0x79,0x44,0xe0,0xb6}}
// {0xc9a6f085,0x8ea1,0x4825,{0xa8,0x74,0x03,0xdf,0x26,0xba,0xed,0x92}}
// {0xed2922f4,0x664b,0x4c85,{0xb6,0x0d,0x01,0xcd,0x3c,0x20,0xcf,0x1d}}
// {0xbaed4d04,0x772f,0x47a7,{0xac,0x87,0xb3,0xd1,0x3c,0x0f,0x8c,0xdc}}
// {0x0cba6b46,0xce6d,0x41c7,{0x99,0x17,0x0f,0x41,0x5a,0x50,0x0a,0xfb}}
// {0x1e8e6ac6,0x163c,0x43d4,{0x9d,0x36,0x1b,0x3e,0x04,0x13,0x73,0x0c}}

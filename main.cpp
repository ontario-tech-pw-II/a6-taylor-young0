#include <iostream>
#include "str.h"

using namespace std;

int main(int argc, char const *argv[]) {
  str raptors = str("Toronto Raptors");
  str leafs = str("Toronto Maple Leafs");

  cout << "***Printing raptors and leafs: " << '\n';
  raptors.print();
  leafs.print();
  cout << '\n';

  cout << "***Setting raptors to be equal to leafs" << '\n';
  raptors = leafs;
  raptors.print();
  leafs.print();
  cout << '\n';

  cout << "***Deleted raptors" << '\n';
  raptors.clear();
  raptors.print(); // Prints blank line
  leafs.print(); // Raptors deletion doesn't affect leafs
  cout << '\n';


  cout << "***Created blueJays" << '\n';
  str blueJays = str("Toronto Blue Jays");
  blueJays.print();
  cout << '\n';

  cout << "***Combined blueJays + leafs" << '\n';
  str blueJaysLeafs = blueJays + leafs;
  blueJaysLeafs.print();
  cout << '\n';

  cout << "***Printing raptors, leafs, blueJays, blueJaysLeafs: " << '\n';
  raptors.print();
  leafs.print();
  blueJays.print();
  blueJaysLeafs.print();
  cout << '\n';

  cout << "***Input into otherTeam" << '\n';
  str otherTeam;
  cin >> otherTeam;
  cout << '\n';

  cout << "***Printing raptors, leafs, blueJays, blueJaysLeafs, otherTeam: " << '\n';
  raptors.print();
  leafs.print();
  blueJays.print();
  blueJaysLeafs.print();
  otherTeam.print();
  cout << '\n';

  cout << "***cout << otherTeam" << '\n';
  cout << otherTeam << '\n';

  return 0;
}

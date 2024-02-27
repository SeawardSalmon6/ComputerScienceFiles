#include "trie.h"
#include <iostream>

int main()
{
  Trie t(256);
  t.insert("amor");
  t.insert("amar");
  t.insert("amaranto");
  t.insert("amargo");
  t.insert("amigável");
  t.insert("wax");
  t.insert("was");
  t.insert("what");
  t.insert("word");
  t.insert("work");
  t.insert("parangaricutirimiruaro");
  t.insert("paraná");
  t.insert("parcimônia");

  std::cout
      << t.search("amor") << std::endl;

  t.searchByPrefix("a");
  t.searchByPrefix("par");

  t.deleteNode("amor");
  return 0;
}
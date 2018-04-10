use BlockDist;
proc foo(d : domain) where d.dist : Block {
  writeln("Block-distributed domain");
}
proc foo(d : domain) {
  writeln("Unknown distribution");
}
var D = {1..10} dmapped Block({1..10});
foo(D);

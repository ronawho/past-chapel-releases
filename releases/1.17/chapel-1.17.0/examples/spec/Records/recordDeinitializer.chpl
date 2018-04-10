class C { var x: int; } // A class with nonzero size.
// If the class were empty, whether or not its memory was reclaimed
// would not be observable.

// Defines a record implementing simple memory management.
record R {
  var c: C;
  proc R() { c = new C(0); }
  proc deinit() { delete c; c = nil; }
}

proc foo()
{
  var r: R; // Initialized using default constructor.
  writeln(r);
  // r will go out of scope here.
  // Its deinitializer will be called to free the C object it contains.
}

foo();

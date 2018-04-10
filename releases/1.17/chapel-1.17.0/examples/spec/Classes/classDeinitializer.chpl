class C {
  var i,j,k: int;
  proc deinit() { writeln("Bye, bye."); }
}

var c : C = nil;
delete c;        // Does nothing: c is nil.

c = new C();     // Creates a new object.
delete c;        // Deletes that object: Writes out "Bye, bye."
                 // and reclaims the memory that was held by c.

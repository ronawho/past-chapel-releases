var A: [1..3] int;
var B: [1..3] int;
A = -1;
B = 1;
writeln(A);
writeln(B);
A = B;
writeln(A);
writeln(B);
A = -2;
B = 2;
writeln(A);
writeln(B);
forall (a,b) in zip(A,B) do
  a = b;
writeln(A);
writeln(B);

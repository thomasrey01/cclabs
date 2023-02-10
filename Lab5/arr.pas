{ This program does some work on arrays, passing them by value and by reference and such }
program arr;

const N = 5;

var arr : array [5 .. 6] of real;

function some (rra : array [1 .. 2] of real; y : real; z : real) : real;
begin
    some := rra[1] + y + z
end;

procedure some2 (var rra : array [2 .. 3] of real);
begin
    rra[3] := rra[3] + 20
end;

begin
    readln(arr[5], arr[6]);
    writeln(some(arr, arr[5], N));
    writeln(some(arr, 5, 5.6));
    some2(arr);
    writeln(arr[5], arr[6])
end.
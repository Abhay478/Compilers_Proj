enum Bar {
    Zero,
    One,
    Two
}

struct Foo {
    a: u8,
    b: u32,
    c: char,
    var: Bar
}


fn foo(): u32 {
  return 2;
}

fn main() {
  let b: u8;
  let a: u32;
  let c: u32 = foo();

  switch((a+c)%2) {
		case 0 => { b = 0;}
    default => {print("Default case");}
   }

  for(a = 0; a < 4; a++){
    b++;
  }

}

enum Bar {
    One,
    Two,
    Three
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

forge (a: Bar) as (b: u32) {
  switch(a) {
    case Bar::One => {b = 1;}
    case Bar::Two => {b = 2;}
    case Bar::Three => {b = 3;}
  }
}

forge (a: u32) as (b: Bar) {
  switch(a) {
    case 1 => {b = Bar::One;}
    case 2 => {b = Bar::Two;}
    case 3 => {b = Bar::Three;}
    default => {b = Bar::One;}
  }
}

fn main() {
  let b: u8;
  let a: Bar;
  a = Bar::One;
  let c: u32 = foo();

  switch(a) {
		case Bar::Zero => { b = 0;}
    case Bar::One => {b = 1;}
    default => {print("Default case");}
   }
  for(a = 0 as (Bar); a as (u32) < 4; a = (a as (u32) + 1) as (Bar)){
    b++;
  }

}

enum Parity {
  Even,
  Odd
}

forge (a: u8) as (b: [[u8]]) {
  b[0][0] = a;
}

forge (a: u8) as (b: Parity) {
  if (a > 1) {
    b = (a - 2) as (Parity);
  }
  if (a == 1) {
    b = Parity::Odd;
  } else {
    b = Parity::Even;
  }
}

forge (a: u8, b: u8) as (c: Parity) {
  if (a % 2 == 0 && b % 2 == 0) {
    c = Parity::Even;
  } else {
    c = Parity::Odd;
  }
}

fn main() {
  let a: Parity = 1 as (Parity); // a is now Parity::Odd
  let b: Parity = (1, 2) as (Parity); /* b is
                                        now Parity::Odd */
}

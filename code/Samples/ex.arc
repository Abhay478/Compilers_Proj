enum Parity {
  Even,
  Odd
}

forge (a: u8) as (Parity) {
  if (a % 2 == 0) {
    return Parity::Even;
  } else {
    return Parity::Odd;
  }
}

forge (a: u8, b: u8) as (Parity) {
  if (a % 2 == 0 && b % 2 == 0) {
    return Parity::Even;
  } else {
    return Parity::Odd;
  }
}

fn main() {
  let a: Parity = 1 as (Parity); // a is now Parity::Odd
  let b: Parity = (1, 2) as (Parity); /* b is
                                        now Parity::Odd */
}

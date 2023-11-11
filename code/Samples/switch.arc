enum Parity {
   Even, 
   Odd
}

forge (a: u8) as (b: Parity) {
   switch(a%2) {
		case 0 => { b = Parity::Even;}
		case 1 => { b = Parity::Odd; }
   }
}

let u: Parity;

fn main() {
    let u: Parity = 7 as (Parity); // u will be Parity::Odd.
}

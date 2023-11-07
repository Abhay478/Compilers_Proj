enum Parity {
   Even, 
   Odd
}

forge (a: u8) as (Parity) {
   switch(a%2) {
		case 0: return Parity::Even;
		case 1: return Parity::Odd;
   }
}

let u: Parity = 7 as (Parity); // u will be Parity::Odd.

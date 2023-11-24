enum Color {
    Red,
    Green,
    Blue
}

struct Point {
    x: float,
    y: float,
    color: Color
}

fn printPoint(p: Point) {
    switch (p.color) {
        case Color::Red => { print("Red"); }
        case Color::Green => { print("Green"); }
        case Color::Blue => { print("Blue"); }
    }
}

claim Point is Group {
    (result = 0) => {
        result.x = 0.0;
        result.y = 0.0;
        result.color = Color::Red; // Default color
    }
    
    (result = a + b) => {
        result.x = a.x + b.x;
        result.y = a.y + b.y;
        result.color = a.color; // Assuming color addition is not defined
    }

    (result = -a) => {
        result.x = -a.x;
        result.y = -a.y;
        result.color = a.color; // Assuming color negation is not defined
    }
}

fn main(): i32 {
    let p1: Point;
    p1.x = 1.0;
    p1.y = 2.0;
    p1.color = Color::Red;

    let p2: Point; 
    p2.x = 3.2;
    p2.y = 5.55;
    p2.color = Color::Red;

    let p3: Point = p1 + p2; // Using group operation

    return 0;
}

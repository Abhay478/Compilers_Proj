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
    print("Point(");
    print(p.x);
    print(", ");
    print(p.y);
    print(", ");
    switch (p.color) {
        case Red => { print("Red"); }
        case Green => { print("Green"); }
        case Blue => { print("Blue"); }
    }
    print(")");
}

claim Point is Group {
    (result = a + b) => {
        result.x = a.x + b.x;
        result.y = a.y + b.y;
        result.color = a.color; // Assuming color addition is not defined
    }

    (result = 0) => {
        result.x = 0.0;
        result.y = 0.0;
        result.color = Color::Red; // Default color
    }

    (result = -a) => {
        result.x = -a.x;
        result.y = -a.y;
        result.color = a.color; // Assuming color negation is not defined
    }
}

fn main(): i32 {
    let p1: Point = {x: 1.0, y: 2.0, color: Color::Red};
    let p2: Point = {x: 3.0, y: 4.0, color: Color::Blue};

    let p3: Point = p1 + p2; // Using group operation
    printPoint(p3);

    return 0;
}

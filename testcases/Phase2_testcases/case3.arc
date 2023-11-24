enum Status {
    Active,
    Inactive,
    Unknown
}

struct Employee {
    id: u32,
    name: str,
    status: Status
}

fn updateStatus(emp: Employee, newStatus: Status): Employee {
    emp.status = newStatus;
    return emp;
}

fn fibonacci(n: u32): [u32] {
    let fib: [u32] = [0, 1];
    for (let i: u32 = 2; i < n; i++) {
        let next: u32 = fib[i - 1] + fib[i - 2];
        push(fib, next);
    }
    return fib;
}

fn main(): i32 {
    let e: Employee;
    e.id = 123;
    e.name = "Sumedh";
    e.status = Status::Active;

    let updatedEmployee: Employee = updateStatus(e, Status::Inactive);

    let fibSeries: [u32] = fibonacci(10);
    for num: u32 in fibSeries {

        print(num as (str));
    }

    return 0;
}

use std::fs;
use std::str::Split;

fn print_type_of<T>(_: &T) {
    println!("{}", std::any::type_name::<T>())
}

enum Direction {
    Down(u64),
    Up(u64),
    Forward(u64)
}

fn read_vals() -> Vec<Direction> {
    let file_data = fs::read_to_string("input2").expect("unable to read file");
    return file_data.split("\n")
        .map(|x| {
            let splits: Vec<&str> = x.split(" ").collect();
            let units = splits[1].parse().unwrap();
            match splits[0] {
                "forward" => Direction::Forward(units),
                "up" => Direction::Up(units),
                "down" => Direction::Down(units),
                command => panic!("wtf {}", command),
            }
        })
        .collect()
}

fn p2() {
    let mut depth = 0;
    let mut horizontal = 0;
    for direction in read_vals() {
        match direction {
            Direction::Down(val) => depth+=val,
            Direction::Up(val) => depth-=val,
            Direction::Forward(val) => horizontal+=val,
        }
    }

    print!("down*forward: {}\n", depth*horizontal);
    
}

fn p2_2() {
    let mut depth = 0;
    let mut horizontal = 0;
    let mut aim = 0;
    
    for direction in read_vals() {
        match direction {
            Direction::Down(val) => aim+=val,
            Direction::Up(val) => aim-=val,
            Direction::Forward(val) => {
                horizontal += val;
                depth += aim*val;
            },
        }
    }

    print!("d*f: {}\n", depth*horizontal)
}


fn main() {
    p2_2();
}

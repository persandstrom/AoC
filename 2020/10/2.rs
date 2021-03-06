use std::io::{self, BufRead};
use std::vec::Vec;
use std::time::{Duration, SystemTime};

fn main() {
    let stdin = io::stdin();
    let mut adapters = Vec::new();
    adapters.push(0);
    for line in stdin.lock().lines() {
        adapters.push(line.unwrap().parse::<i32>().unwrap());
    }
    
    let start = SystemTime::now();
    adapters.sort();
    adapters.push(adapters.last().unwrap() + 3);

    let mut sums = Vec::new();
    sums.push(1);
    for pos in 1..adapters.len()-1 {
        let mut sum = 0i64;
        let mut bt = pos - 1;
        while adapters[pos] - adapters[bt] <= 3 {
            sum += sums[bt];
            if bt == 0 {
                break;
            }
            bt -= 1;
        }
        sums.push(sum)
    }
    println!("{:?}", start.elapsed());
    println!("{:?}", sums.last().unwrap());
}

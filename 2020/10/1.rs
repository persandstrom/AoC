use std::io::{self, BufRead};
use std::vec::Vec;

fn main() {
    let stdin = io::stdin();
    let mut adapters = Vec::new();
    adapters.push(0);
    for line in stdin.lock().lines() {
        adapters.push(line.unwrap().parse::<i32>().unwrap());
    }
    adapters.sort();
    
    let mut diff1 = 0;
    let mut diff3 = 1;
    let mut output = 0;
    for adapter in adapters.iter() {
        let diff = adapter - output;
        if diff == 1 {
            diff1+=1;
        }
        if diff == 3 {
            diff3+=1;
        }
        output = *adapter;
    }

    println!("{}", diff1 * diff3);
}

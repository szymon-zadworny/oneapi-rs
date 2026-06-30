use oneapi_rs::platform::Platform;
use oneapi_rs::info::platform::*;

fn main() {
    for platform in Platform::get_platforms() {
        println!("Platform:");
        println!("- Name: {}", platform.get_info::<Name>());
        println!("- Vendor: {}", platform.get_info::<Vendor>());
        println!("- Vendor: {}", platform.get_info::<Vendor>());
    }
}

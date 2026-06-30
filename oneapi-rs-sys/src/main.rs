#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("oneapi-rs-sys/include/shim.hpp");
        #[namespace = "sycl"]
        type platform;
        fn get_platforms() -> UniquePtr<CxxVector<platform>>;
        fn get_name(p: &platform) -> UniquePtr<CxxString>;
    }
}

fn main() {
    for platform in &*ffi::get_platforms() {
        println!("{}", ffi::get_name(platform));
    }
}

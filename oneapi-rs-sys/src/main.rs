#[cxx::bridge(namespace = "sycl_shims")]
mod sycl {
    unsafe extern "C++" {
        include!("oneapi-rs-sys/include/platform.hpp");
 
        type Platform;

        #[Self = "Platform"]
        fn get_platforms() -> UniquePtr<CxxVector<Platform>>;

        fn get_version(&self) -> String;
        fn get_name(&self) -> String;
        fn get_vendor(&self) -> String;
    }
}

fn main() {
    for platform in &*sycl::Platform::get_platforms() {
        println!("[{}] [{}] [{}]", platform.get_version(), platform.get_name(), platform.get_vendor());
    }
}

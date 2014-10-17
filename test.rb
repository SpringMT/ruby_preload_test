ENV.store("DYLD_FORCE_FLAT_NAMESPACE", '1')
ENV.store("DYLD_INSERT_LIBRARIES", "./preload_test.dylib")

puts 1


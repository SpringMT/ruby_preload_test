require "bundler/gem_tasks"

require "rake/extensiontask"

task :build => :compile

Rake::ExtensionTask.new("ruby_preload_test") do |ext|
  ext.lib_dir = "lib/ruby_preload_test"
end

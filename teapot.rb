# Teapot v3.4.0 configuration generated at 2020-06-09 00:37:26 +1200

required_version "3.0"

define_project "splines" do |project|
	project.title = "Splines"
end

# Build Targets

define_target 'splines-library' do |target|
	target.depends 'Language/C++14'
	
	target.provides 'Library/Splines' do
		source_root = target.package.path + 'source'
		
		library_path = build static_library: 'Splines', source_files: source_root.glob('Splines/**/*.cpp')
		
		append linkflags library_path
		append header_search_paths source_root
	end
end

define_target 'splines-test' do |target|
	target.depends 'Library/Splines'
	target.depends 'Library/UnitTest'
	
	target.depends 'Language/C++14'
	
	target.provides 'Test/Splines' do |arguments|
		test_root = target.package.path + 'test'
		
		run tests: 'Splines', source_files: test_root.glob('Splines/**/*.cpp'), arguments: arguments
	end
end

define_target 'splines-executable' do |target|
	target.depends 'Library/Splines'
	
	target.depends 'Language/C++14'
	
	target.provides 'Executable/Splines' do
		source_root = target.package.path + 'source'
		
		executable_path = build executable: 'Splines', source_files: source_root.glob('Splines.cpp')
		
		splines_executable executable_path
	end
end

define_target 'splines-run' do |target|
	target.depends 'Executable/Splines'
	
	target.depends :executor
	
	target.provides 'Run/Splines' do |*arguments|
		run executable_file: environment[:splines_executable], arguments: arguments
	end
end

# Configurations

define_configuration 'development' do |configuration|
	configuration[:source] = "https://github.com/kurocha"
	configuration.import "splines"
	
	# Provides all the build related infrastructure:
	configuration.require 'platforms'
	
	# Provides unit testing infrastructure and generators:
	configuration.require 'unit-test'
	
	# Provides some useful C++ generators:
	configuration.require 'generate-cpp-class'
	
	configuration.require "generate-project"
	configuration.require "geometry"
end

define_configuration "splines" do |configuration|
	configuration.public!
end

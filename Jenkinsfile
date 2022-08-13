pipeline {
	agent any
		options {
		buildDiscarder(logRotator(numToKeepStr: '10'))
	}
	parameters {
		
		booleanParam name: 'SIMV', defaultValue: true, description: 'Run build with simvol?'
		booleanParam name: 'NO_SIMV', defaultValue: true, description: 'Run build without simvol?'		
	}
	stages {

		stage('Make CMake with simvol')
		{
			when {
                	environment name: 'SIMV', value: 'true'
            		}
			steps
			{
				 script {
			bat encoding: 'Windows-1251', script: ''' 		
			set path=%path:\"=%
			RMDIR build /s /q
			MKDIR build
			CD build
			call "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/VC/Auxiliary/Build/vcvars64.bat" 
  			call "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake" -G "Ninja" -DCMAKE_BUILD_TYPE:STRING=RelWithDebInfo -DCMAKE_TOOLCHAIN_FILE=D:/vcpkg/scripts/buildsystems/vcpkg.cmake ../	
                '''	
			}
			}
		}
			stage('Build and install with simvol')
		{
			when {
                	environment name: 'SIMV', value: 'true'
            		}
			steps
			{
				 script {
			bat encoding: 'Windows-1251', script: ''' 		
			set path=%path:\"=%
	
			CD build
  			call "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/VC/Auxiliary/Build/vcvars64.bat" 
			call "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake"  --build ./
			call "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake"  --install ./ -j 8

                '''	
			}
			}
		}
		stage('Make CMake without simvol')
		{
			when {
                	environment name: 'NO_SIMV', value: 'true'
            		}
			steps
			{
				 script {
			bat encoding: 'Windows-1251', script: ''' 		
			set path=%path:\"=%
			RMDIR build /s /q
			MKDIR build
			CD build
			call "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/VC/Auxiliary/Build/vcvars64.bat" 
  			call "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake" -G "Ninja" -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_TOOLCHAIN_FILE=D:/vcpkg/scripts/buildsystems/vcpkg.cmake ../	
                '''	
			}
			}
		}
			stage('Build and install without simvol')
		{
			when {
                	environment name: 'NO_SIMV', value: 'true'
            		}
			steps
			{
				 script {
			bat encoding: 'Windows-1251', script: ''' 		
			set path=%path:\"=%
	
			CD build
  			call "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/VC/Auxiliary/Build/vcvars64.bat" 
			call "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake"  --build ./
			call "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake"  --install ./

                '''	
			}
			}
		}
		
	}
	
}

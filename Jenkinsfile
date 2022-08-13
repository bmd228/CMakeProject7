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

		stage('Build with simvol')
		{
			when {
                	environment name: 'SIMV', value: 'true'
            		}
			steps
			{
				 script {
			bat encoding: 'Windows-1251', script: ''' 		
			set path=%path:\"=%
			call "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/VC/Auxiliary/Build/vcvars64.bat" 
  			call "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake" -G "Ninja" -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_TOOLCHAIN_FILE=D:/vcpkg/scripts/buildsystems/vcpkg.cmake %cd%
			call "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake" -S ./ 
                '''	
			}
			}
		}
	
		stage('Build without simvol')
		{
			when {
                	environment name: 'NO_SIMV', value: 'true'
            		}
			steps
			{	
			cmake arguments: '-DCMAKE_TOOLCHAIN_FILE=D:/vcpkg/scripts/buildsystems/vcpkg.cmake', installation: '12'
                	cmakeBuild  buildType: 'Release', cleanBuild: true, installation: '12', steps: [[withCmake: true]]
			}
		}
	}
	
}

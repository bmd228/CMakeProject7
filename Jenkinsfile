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
        stage('Run environment VS') 
	{
		steps 
		{
                bat '''
		set path=%path:\"=%
                    call "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Enterprise\\VC\\Auxiliary\\Build\\vcvars64.bat" 
                '''		
            	}
           
        }
		stage('Build with simvol')
		{
			when {
                	environment name: 'SIMV', value: 'true'
            		}
			steps
			{
			cmake arguments: '-DCMAKE_TOOLCHAIN_FILE=D:/vcpkg/scripts/buildsystems/vcpkg.cmake', installation: '13'
                	cmakeBuild   buildType: 'RelWithDebInfo', cleanBuild: true, installation: '13', steps: [[withCmake: true]]
			cmake arguments: '--install', installation: '13'
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

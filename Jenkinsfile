pipeline {
	agent any
	
	stages {		
        stage('Build') {
		steps {
                bat '''
		set path=%path:\"=%
                    call "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Enterprise\\VC\\Auxiliary\\Build\\vcvars64.bat" 
                '''
            }
            steps {     

                cmake arguments: '-DCMAKE_TOOLCHAIN_FILE=D:/vcpkg/scripts/buildsystems/vcpkg.cmake', installation: '12'
                cmakeBuild buildType: 'Release', cleanBuild: true, installation: '12', steps: [[withCmake: true]]

            }
        }
	
}

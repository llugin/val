pipeline {
    agent any
    parameters {
        string (
            defaultValue: 'master',
            description: '',
            name : 'BRANCH_PATTERN')
    }

    stages {
        stage ('Prepare') {
            steps {
		sh 'rm -rf *'
                checkout([$class: 'GitSCM',
                    branches: [[name: "origin/${BRANCH_PATTERN}"]],
                    doGenerateSubmoduleConfigurations: false,
                    extensions: [[$class: 'LocalBranch']],
                    submoduleCfg: [],
                    userRemoteConfigs: [[
                        credentialsId: 'jenkins',
                        url: 'https://github.com/mramotowski/val']]])
            }
        }

	stage ('Build') {
	    steps {
		sh 'make'
	    }
	}

	stage ('Test') {
	    steps {
		sh './test --gtest_output="xml:result.xml"'
	    }
	}
    }
    post {
        always {
            junit 'result.xml'
        }
    }
}

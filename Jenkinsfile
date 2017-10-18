pipeline {
    agent any
    stages {
        stage ('Prepare') {
            steps {
		sh 'rm -rf *'
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

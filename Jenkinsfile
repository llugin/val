pipeline {
    agent any

    stages {
        stage ('Prepare') {
            steps {
		sh 'ls'
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

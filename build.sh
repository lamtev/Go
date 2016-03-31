#!/usr/bin/env bash
export PATH=$PATH:/opt/Qt5.5.0/5.5/gcc_64/bin/

buildReleaseVersion() {
	mkdir build 
	cd build
	mkdir release
	cd release
	cmake --version
    cmake –G "Unix Makefiles" ../../sources

	if [ -e "Makefile" ]; then
		cmake --build ./ --target GoCUI --
		cd ../..
	else
	    cd ../..
		echo "Makefile does not exist"
		echo "Build of release version failed!"
		exit 1
	fi
	ls
}

buildDebugVersion() {
    cd sources
    cloc --version
	cloc --by-file --xml --out=../report/cloc/log *
	cd ../build
	mkdir debug
	cd debug
	cmake --version
	cmake –G "Unix Makefiles" ../../sources
	if [ -e "Makefile" ]; then
		cmake --build ./ --clean-first --

		cd ../../sources
		
		cppcheck --version
		cppcheck --enable=all -v  --xml  * 2> ../report/cppcheck/log
		
		../build/debug/GoTests/FunctionalTest/FTest -xml -o ../report/tests/functional/log || true

        cd ../build/debug/GoEngine/CMakeFiles/GoEngine.dir
        ls
		#gcovr --version
		#gcovr -r . --xml --exclude='' -o ../../../../../report/gcovr/log

		cd ../../../../../sources
		ls
		valgrind --version
		valgrind --leak-check=full --xml=yes --xml-file=/opt/tomcat/.jenkins/jobs/Go/workspace/report/valgrind/functionalTest/FTest.%p /opt/tomcat/.jenkins/jobs/Go/workspace/build/debug/GoTests/FunctionalTest/FTest || true
		

        cd ../report/doxygen
		if [ -e "goconfig" ]; then
			doxygen --version
			doxygen goconfig
		else
			echo "Doxygen failed"
			echo "goconfig does not exist"
		fi

		cd ../..
	else
	    cd ..
		echo "Makefile does not exist"
		echo "Build of debug version failed!"
		exit 1
	fi
}

makeReport() {
	cd report/doxygen/
	ls
	if [ -e "goconfig" ]; then
			doxygen --version
			doxygen goconfig
		else
			echo "Doxygen failed"
			echo "goconfig does not exist"
	fi
	cd latex
	if [ -e "Makefile" ]; then
		make --version
		make
		cd ../../..
	else
		echo "Makefile does not exist"
		echo "Report failure!"
		cd ../../..
		exit 1
	fi
}

zipFiles() {
    ls
	if [ -z ${JOB_NAME} ] || [ -z ${BUILD_NUMBER}]; then
		echo "Vars JOB_NAME/BUILD_NUMBER are unset"
		echo "Zip failure!"
		exit 1
	fi

	TITLE="${JOB_NAME}_v${BUILD_NUMBER}"
	mkdir "$TITLE"

	if [ -e "build/release/GoCUI/GoCUI" ]; then
		cp build/release/GoCUI/GoCUI $TITLE/Go_v${BUILD_NUMBER}
		if [ -e "report/doxygen/latex/refman.pdf" ]; then
			cp report/doxygen/latex/refman.pdf $TITLE/Go_v${BUILD_NUMBER}.pdf
		fi
		zip --version
		zip $TITLE.zip $TITLE/*
	else
		echo "GoCUI does not exist"
		echo "Zip failure!"
		exit 1
	fi

}

clean() {
	git clean -f -e *.zip *.pdf
}

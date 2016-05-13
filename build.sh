#!/usr/bin/env bash

export PATH=$PATH:/opt/Qt5.5.0/5.5/gcc_64/bin/

build_release() {
	mkdir build 
	cd build
	mkdir release
	cd release
	cmake --version
    cmake -D CMAKE_BUILD_TYPE=Release –G "Unix Makefiles" ../../sources

	if [ -e "Makefile" ]; then
		cmake --build ./ --target GoCUI --
		cmake --build ./ --target GoGUI --
	else
		echo "Makefile does not exist"
		echo "Build of release version failed!"
		exit 1
	fi
	cd ../..
	ls
}

build_debug() {
    cd sources
    cloc --version
	cloc --by-file --xml --out=../report/cloc/clocLog.xml *
	cd ../build
	mkdir debug
	cd debug
	cmake --version
	cmake -D CMAKE_BUILD_TYPE=Debug –G "Unix Makefiles" ../../sources
	if [ -e "Makefile" ]; then
		cmake --build ./ --clean-first --

		cd ../../report
		mkdir tests
		mkdir cppcheck
		mkdir valgrind
		cd ../sources
		
		
		../build/debug/GoTests/FunctionalTest/FTest -xml -o ../report/tests/FunctionalTestLog.xml || true
		../build/debug/GoTests/UnitTests/StoneTest -xml -o  ../report/tests/StoneTestLog.xml || true
		../build/debug/GoTests/UnitTests/PointTest -xml -o  ../report/tests/PointTestLog.xml || true
		../build/debug/GoTests/UnitTests/BoardTest -xml -o  ../report/tests/BoardTestLog.xml || true
		../build/debug/GoTests/UnitTests/MoveTest -xml -o  ../report/tests/MoveTestLog.xml || true
		../build/debug/GoTests/UnitTests/GameProcessTest -xml -o  ../report/tests/GameProcessTestLog.xml || true
		cppcheck --version
		cppcheck --language=c++ --std=c++11 --enable=all -v --xml-version=2  * 2> ../report/cppcheck/cppcheckLog.xml
		
        ls
		
		valgrind --version
		valgrind --leak-check=full --xml=yes --xml-file=/opt/tomcat/.jenkins/jobs/Go/workspace/report/valgrind/FunctionalTest.%p.xml /opt/tomcat/.jenkins/jobs/Go/workspace/build/debug/GoTests/FunctionalTest/FTest || true
		valgrind --leak-check=full --xml=yes --xml-file=/opt/tomcat/.jenkins/jobs/Go/workspace/report/valgrind/StoneTest.%p.xml /opt/tomcat/.jenkins/jobs/Go/workspace/build/debug/GoTests/UnitTests/StoneTest || true
		valgrind --leak-check=full --xml=yes --xml-file=/opt/tomcat/.jenkins/jobs/Go/workspace/report/valgrind/PointTest.%p.xml /opt/tomcat/.jenkins/jobs/Go/workspace/build/debug/GoTests/UnitTests/PointTest || true
		valgrind --leak-check=full --xml=yes --xml-file=/opt/tomcat/.jenkins/jobs/Go/workspace/report/valgrind/BoardTest.%p.xml /opt/tomcat/.jenkins/jobs/Go/workspace/build/debug/GoTests/UnitTests/BoardTest || true
		valgrind --leak-check=full --xml=yes --xml-file=/opt/tomcat/.jenkins/jobs/Go/workspace/report/valgrind/MoveTest.%p.xml /opt/tomcat/.jenkins/jobs/Go/workspace/build/debug/GoTests/UnitTests/MoveTest || true
		valgrind --leak-check=full --xml=yes --xml-file=/opt/tomcat/.jenkins/jobs/Go/workspace/report/valgrind/GameProcessTest.%p.xml /opt/tomcat/.jenkins/jobs/Go/workspace/build/debug/GoTests/UnitTests/GameProcessTest || true

	else
	    cd ..
		echo "Makefile does not exist"
		echo "Build of debug version failed!"
		exit 1
	fi
}

make_report() {
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

zip_artifacts() {
    ls
	if [ -z ${JOB_NAME} ] || [ -z ${BUILD_NUMBER}]; then
		echo "Vars JOB_NAME/BUILD_NUMBER are unset"
		echo "Zip failure!"
		exit 1
	fi

	TITLE="${JOB_NAME}_v${BUILD_NUMBER}"
	mkdir "$TITLE"
	
	if [ -e "build/release/GoCUI/GoCUI" ]; then
		cp build/release/GoCUI/GoCUI $TITLE/GoCUI_v${BUILD_NUMBER}
	else
		echo "GoCUI does not exist"
	fi
	
	if [ -e "build/release/GoGUI/GoGUI" ]; then
		cp build/release/GoGUI/GoGUI $TITLE/GoGUI_v${BUILD_NUMBER}
	else
		echo "GoGUI does not exist"
	fi
	
	if [ -e "report/doxygen/latex/refman.pdf" ]; then
		cp report/doxygen/latex/refman.pdf $TITLE/Go_v${BUILD_NUMBER}.pdf
	else
		echo "refman.pdf does not exist"
	fi
	
	if [ -e "build/release/GoCUI/GoCUI" || -e "build/release/GoGUI/GoGUI" || -e "report/doxygen/latex/refman.pdf" ]; then
		zip --version
		zip $TITLE.zip $TITLE/*
	else
		echo "GoCUI, GoGUI and refman.pdf do not exist"
		echo "Zip failure!"
		exit 1
	fi

}

clean() {
	git clean -f -e *.zip *.pdf
}

JUNIT = junit-platform-console-standalone-1.2.0.jar
CP = ".:test:$$HOME/lib/java/$(JUNIT)"

A01InsertionSort:
	javac -cp $(CP) test/$@Test.java
	java $@
	java -jar ~/lib/java/$(JUNIT) -cp $(CP) --scan-classpath

junit:
	mkdir -p ~/lib/java
	wget -O ~/lib/java/$(JUNIT) "http://search.maven.org/remotecontent?filepath=org/junit/platform/junit-platform-console-standalone/1.2.0/$(JUNIT)"

clean:
	find . -name "*.class" -exec rm {} +

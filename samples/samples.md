#JAVA#

##JAVA_HOME##

###Using getProperty("java.home")###

http://askubuntu.com/questions/459900/how-to-find-my-current-java-home-in-ubuntu

~~~
$ jrunscript -e 'java.lang.System.out.println(java.lang.System.getProperty("java.home"));'
$ export JAVA_HOME="$(jrunscript ...)"
~~~

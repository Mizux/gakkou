# Create a virtual environment with all tools installed
# ref: https://hub.docker.com/_/ubuntu
FROM ubuntu:rolling AS env
LABEL maintainer="mizux.dev@gmail.com"
# Install system build dependencies
ENV PATH=/usr/local/bin:$PATH
RUN ln -snf /usr/share/zoneinfo/Europe/Paris /etc/localtime \
&& echo Europe/Paris > /etc/timezone

RUN apt update -qq \
&& apt install -yq \
git wget libssl-dev build-essential \
qt5-default \
&& apt-get clean \
&& rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
# Install CMake 3.17.2
RUN wget "https://cmake.org/files/v3.17/cmake-3.17.2-Linux-x86_64.sh" \
&& chmod a+x cmake-3.17.2-Linux-x86_64.sh \
&& ./cmake-3.17.2-Linux-x86_64.sh --prefix=/usr/local/ --skip-license \
&& rm cmake-3.17.2-Linux-x86_64.sh
CMD [ "/bin/sh" ]

FROM env AS devel
WORKDIR /home/app
COPY . .

FROM devel AS build
RUN cmake -version
RUN cmake -S. -Bbuild
RUN cmake --build build --target all -v
RUN cmake --build build --target install

FROM build AS test
RUN cmake --build build --target test

FROM ubuntu:rolling AS env
LABEL maintainer="mizux.dev@gmail.com"
# Install system dependencies
RUN apt-get update -qq \
&& apt-get install -yq \
qt5-default \
&& apt-get clean \
&& rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Create app directory
WORKDIR /home/app
COPY --from=build /home/app/build/install .

CMD [ "/bin/sh" ]

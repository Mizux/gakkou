# Create a virtual environment with all tools installed
# ref: https://hub.docker.com/_/alpine
FROM alpine:edge AS env
# Install system dependencies
ENV PATH=/usr/local/bin:$PATH
RUN apk add --no-cache \
 git g++ clang make cmake \
 doxygen graphviz \
 qt5-qtbase-dev ttf-freefont

FROM env AS devel
WORKDIR /home/project
COPY . .

FROM devel AS build
RUN cmake --version
RUN cmake -S. -Bbuild
RUN cmake --build build --target all -v
RUN cmake --build build --target install -v

FROM build AS test
RUN cmake --build build --target test

# Create a production image
FROM alpine:edge AS prod
RUN apk add --no-cache qt5-qtbase-x11 ttf-freefont
# Create app directory
WORKDIR /home/app
COPY --from=build /usr/local/ .

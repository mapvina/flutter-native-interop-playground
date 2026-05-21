// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "flmln",
    platforms: [
        .macOS("10.15")
    ],
    products: [
        .library(name: "flmln", targets: ["flmln"])
    ],
    targets: [
        .binaryTarget(
          name: "flmln_xcframework",
          path: "Artifacts/flmln.xcframework"
        ),
        .target(
            name: "flmln",
            dependencies: [
                .target(name: "flmln_xcframework")
            ], 
            packageAccess: true
        )
    ]
)

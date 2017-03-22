![TPLMaps](https://dl.dropboxusercontent.com/s/ks2tbo6ghpwwda0/TPLMapsLogo.png)
TPL Maps, a product of TPL Trakker Ltd. is Pakistan’s first indigenous digital mapping solution. TPL Maps has been created using state of the art technology that will not only provide real time intelligent routing but also give users access to live traffic updates, turn-by-turn navigation and smart search options.

## Getting Started
Before you can begin working with TPL Maps on iOS, you need to download the TPL Maps SDK for iOS.

### Step 1: Get the latest version of Xcode
To build a project using the Google Maps SDK for iOS, you need **version 7.3** or later of [Xcode](https://developer.apple.com/xcode/).

### Step 2: Install the SDK


The TPLMap SDK for iOS is available as a CocoaPods pod. CocoaPods is an open source dependency manager for Swift and Objective-C Cocoa projects.

If you don't already have the CocoaPods tool, install it on macOS by running the following command from the terminal. For details, see the [CocoaPods Getting Started guide](https://guides.cocoapods.org/using/getting-started.html).

> sudo gem install cocoapods

Create a `Podfile` for the TPLMaps SDK for iOS and use it to install the API and its dependencies:

1. If you don't have an Xcode project yet, create one now and save it to your local machine. (If you're new to iOS development, create a Single View Application.)

2. Create a file named `Podfile` in your project directory. This file defines your project's dependencies. 

3. Edit the `Podfile` and add your dependencies. Here is an example which includes the dependencies you need for the TPLMaps SDK for iOS:

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '8.0'

target 'YOUR_APPLICATION_TARGET_NAME_HERE' do
pod 'TPLMaps'
end
```

4. Save the `Podfile`

5. Open a terminal and go to the directory containing the `Podfile`:
```ruby
cd <path-to-project>
```

6. Run the `pod install` command. This will install the APIs specified in the `Podfile`, along with any dependencies they may have.

7. Close Xcode, and then open (double-click) your project's `.xcworkspace` file to launch Xcode. From this time onwards, you must use the `.xcworkspace` file to open the project.

### Step 3: Add a map
The code below demonstrates how to add a simple map to an existing ViewController. If you're creating a new app, first follow the installation instructions above, and create a new **Single View Application**; disabling **Use Storyboards** but enabling Use **Automatic Reference Counting** (ARC).

Now, add or update a few methods inside your app's default ViewController to create and initialize an instance of `TPLMapView`.

```objective-c
- (void)viewDidLoad {
    
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    TPLMapView * mapView = [[TPLMapView alloc] initWithFrame:self.view.frame];
    mapView.showsUserLocation = YES;
    mapView.myLocationButtonEnabled = YES;
    [self.view addSubview:mapView];

    TPLMarker * marker = [TPLMarker markerWithPosition:CLLocationCoordinate2DMake(33.522484, 73.094552)];
    marker.title = @"TPL Trakker";
    marker.subTitle = @"Rawalpindi Office";
    [mapView addMarker:marker];
    
}

```





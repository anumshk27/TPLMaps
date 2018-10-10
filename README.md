![TPLMaps](https://dl.dropboxusercontent.com/s/ks2tbo6ghpwwda0/TPLMapsLogo.png)

## Getting Started
Before you can begin working with TPL Maps on iOS, you need to download the TPL Maps SDK for iOS.

### Step 1: Get the latest version of Xcode
To build a project using the TPL Maps SDK for iOS, you need **version 7.3** or later of [Xcode](https://developer.apple.com/xcode/).

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

#### Add Circle On MapView
```objective-c
    // CLLocationCoordinate2D coordinates
    // CLLocationDistance radius
    TPLCircle * circle = [TPLCircle circleWithCenterCoordinate:coordinates radius:radius];
    circle.outlineWidth=5;
    circle.transparent = YES;
    circle.fillColor = [UIColor purpleColor];
    circle.outlineColor = [UIColor yellowColor];
    circle.zIndex = 1;
    [mapView drawCircle:circle];

```

#### Add Polyline On MapView
```objective-c

  //NSArray * coordinates; contains latitude and longitude values in array.
  int pointCount = (int)[coordinates count];
    CLLocationCoordinate2D *coordinateArray = (CLLocationCoordinate2D *)malloc(pointCount * sizeof(CLLocationCoordinate2D));
    
    for (int i = 0; i < pointCount; ++i) {
        
        double lat = [coordinates[i][@"lat"] doubleValue];
        double lon = [coordinates[i][@"lon"] doubleValue];
        CLLocation *location = [[CLLocation alloc] initWithLatitude:lat longitude:lon];
        coordinateArray[i] = [location coordinate];
        
    }


    TPLPolyLine * polyline = [TPLPolyLine polylineWithCoordinates:coordinateArray count:pointCount];
    polyline.outlineWidth=1;
    polyline.transparent = NO;
    polyline.lineWidth = 5;
    polyline.outlineColor = [UIColor purpleColor];
    polyline.fillColor = [UIColor colorWithRed:255.f/255.f green:111.f/255.f blue:105.f/255.f alpha:.1f];
    [mapView drawPolyLine:polyline];


```
#### Add Polygon On MapView
```objective-c
    
    TPLPolygon *polygon = [TPLPolygon polygonWithCoordinates:coordinateArray count:pointCount];
    polygon.outlineWidth=5;
    polygon.fillColor = [UIColor redColor];
    polygon.transparent = NO;
    polygon.outlineColor = [UIColor colorWithRed:244.0/255.0 green:66.0/255.0 blue:226.0/255.0 alpha:1.0];
    [mapView drawPolygon:polygon];
    
```



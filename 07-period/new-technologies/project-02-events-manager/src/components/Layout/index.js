import { SafeAreaView, useSafeAreaFrame } from "react-native-safe-area-context";
import { styles } from "./styles";
import { Content } from "./Content";
import { ScrollView } from "react-native";
import { Header } from "./Header";

function Layout({ containerStyle, children }) {
  const { height } = useSafeAreaFrame();

  return (
    <SafeAreaView style={[styles.container, containerStyle]}>
      <ScrollView
        contentContainerStyle={[
          styles.scrollViewContainer,
          { paddingBottom: height / 3 },
        ]}
        nestedScrollEnabled
      >
        {children}
      </ScrollView>
    </SafeAreaView>
  );
}

Layout.Header = Header;
Layout.Content = Content;

export { Layout };

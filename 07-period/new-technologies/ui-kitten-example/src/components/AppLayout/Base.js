import { Layout } from "@ui-kitten/components";
import { View } from "react-native";
import { SafeAreaView } from "react-native-safe-area-context";
import { styles } from "./styles";

export function Base({ header, contentStyle, children }) {
  return (
    <Layout style={styles.container}>
      <SafeAreaView style={styles.container}>
        {header}
        <View style={{ ...styles.layout, ...contentStyle }}>{children}</View>
      </SafeAreaView>
    </Layout>
  );
}

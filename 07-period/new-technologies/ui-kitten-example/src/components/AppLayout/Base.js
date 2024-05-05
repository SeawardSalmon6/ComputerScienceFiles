import { Layout } from "@ui-kitten/components";
import { ScrollView, View } from "react-native";
import { SafeAreaView } from "react-native-safe-area-context";
import { styles } from "./styles";

export function Base({ header, contentStyle, children }) {
  return (
    <Layout style={styles.container}>
      <SafeAreaView style={styles.container}>
        {header}
        <ScrollView
          contentContainerStyle={{ ...styles.layout, ...contentStyle }}
        >
          {children}
        </ScrollView>
      </SafeAreaView>
    </Layout>
  );
}

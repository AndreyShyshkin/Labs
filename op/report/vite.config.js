import react from '@vitejs/plugin-react'
import { defineConfig } from 'vite'
import 'vite/modulepreload-polyfill'

// https://vitejs.dev/config/
export default defineConfig({
	plugins: [react()],
	build: {
		manifest: true,
		rollupOptions: {
			input: '/src/main.jsx',
		},
	},
})
